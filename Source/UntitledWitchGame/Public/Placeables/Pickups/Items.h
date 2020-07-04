// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items.generated.h"


UENUM()
enum Item
{
	RuneKey_Moon		UMETA(DisplayName = "Moon Rune"),
	RuneKey_Sun			UMETA(DisplayName = "Sun Rune"),
};

UENUM()
enum WeaponItem
{
	None        UMETA(DisplayName = "None"),
	Broom		UMETA(DisplayName = "Broom"),
};