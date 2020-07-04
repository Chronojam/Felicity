// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Placeables/Pickups/Pickup.h"
#include "Placeables/Pickups/Items.h"
#include "WeaponPickup.generated.h"

UCLASS()
class UNTITLEDWITCHGAME_API AWeaponPickup : public AActor, public IPickup
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	TEnumAsByte<WeaponItem> Type;

public:
	virtual void Pickup(class AStoryPlayerState* State) override;
};
