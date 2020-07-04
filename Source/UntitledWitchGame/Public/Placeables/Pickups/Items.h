// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items.generated.h"


UENUM()
enum Item
{
	RuneKey_Moon		UMETA(DisplayName = "Moon Rune"),
	RuneKey_Sun			UMETA(DisplayName = "Sun Rune"),


	Ability_Broom		UMETA(DisplayName = "Broom"),
	Ability_IceWand		UMETA(DisplayName = "Ice Wand"),
	Ability_FireWand	UMETA(DisplayName = "Fire Wand"),
	Ability_EarthWand	UMETA(DisplayName = "Earth Wand"),
	Ability_AirWand		UMETA(DisplayName = "Air Wand"),
};