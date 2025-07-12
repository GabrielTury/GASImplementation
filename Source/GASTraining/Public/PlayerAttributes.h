// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlayerAttributes.generated.h"

/**
 * 
 */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GASTRAINING_API UPlayerAttributes : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPlayerAttributes();
public:
	UPROPERTY(BlueprintReadOnly, Category = "Player|Attributes")
	FGameplayAttributeData AdditionalMoveSpeed;
	ATTRIBUTE_ACCESSORS(UPlayerAttributes, AdditionalMoveSpeed);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	
	
};
