// Fill out your copyright notice in the Description page of Project Settings.


#include "WalkAbility.h"
#include "GameplayTagContainer.h"

UWalkAbility::UWalkAbility()
{
	SetAssetTags(FGameplayTagContainer(FGameplayTag::RequestGameplayTag(FName("Ability.Walk"))));		
}

void UWalkAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Walk Ability Activated!"));
}
