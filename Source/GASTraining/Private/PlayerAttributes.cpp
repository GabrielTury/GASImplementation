// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttributes.h"

UPlayerAttributes::UPlayerAttributes()
{
	float DefaultAddMoveSpeed = 600.0f;
	InitAdditionalMoveSpeed(DefaultAddMoveSpeed);
}

void UPlayerAttributes::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetAdditionalMoveSpeedAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 400.0f, 800.0f);
	}

}
