// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeaponRandomPotion.generated.h"

/**
 * Handles all the bits for the throwing of potions.
 */
UCLASS()
class UNTITLEDWITCHGAME_API UWeaponRandomPotion : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ThrowPotion();
private:
	bool CurrentlyThrowing;
};
