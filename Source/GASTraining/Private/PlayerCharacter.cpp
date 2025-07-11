

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "WalkAbility.h" // Ensure the header file for UWalkAbility is included

// Sets default values
APlayerCharacter::APlayerCharacter()
{
   // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
   PrimaryActorTick.bCanEverTick = true;

   bUseControllerRotationPitch = false;
   bUseControllerRotationYaw = false;
   bUseControllerRotationRoll = false;

   GetCharacterMovement()->bOrientRotationToMovement = true;
   GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

   // Create a camera boom (pulls in towards the player if there is a collision)
   CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
   CameraBoom->SetupAttachment(RootComponent);
   CameraBoom->TargetArmLength = 400.0f;
   CameraBoom->bUsePawnControlRotation = true;

   // Create a follow camera
   FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
   FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
   FollowCamera->bUsePawnControlRotation = false;
   
   //GAS SETUP
   AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
   FGameplayAbilitySpec WalkSpec(UWalkAbility::StaticClass());
   WalkSpec.InputID = static_cast<int32>(EPlayerAbilityInputID::Move); // Set the input ID for the ability

   AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(WalkSpec));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->TryActivateAbilityByClass(UWalkAbility::StaticClass());
	}	
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Bind movement input
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	}

	//This code is deprecated (works with old Unreal input):
	//FTopLevelAssetPath AbilityEnumAssetPath = FTopLevelAssetPath(FName("/Script/GASTraining"), FName("EPlayerAbilityInputID"));
	//AbilitySystemComponent->BindAbilityActivationToInputComponent(PlayerInputComponent, FGameplayAbilityInputBinds(FString("IA_Move"), AbilityEnumAssetPath, static_cast<int32>(EPlayerAbilityInputID::Move)));
}

void APlayerCharacter::DoMove(float Right, float Forward)
{
}

void APlayerCharacter::DoLook(float Yaw, float Pitch)
{
}

void APlayerCharacter::DoJumpStart()
{
}

void APlayerCharacter::DoJumpEnd()
{
}

