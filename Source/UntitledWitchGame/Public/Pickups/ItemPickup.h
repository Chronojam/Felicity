// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/Pickup.h"
#include "Pickups/Items.h"
#include "GameFramework/Actor.h"
#include "ItemPickup.generated.h"

UCLASS()
class UNTITLEDWITCHGAME_API AItemPickup : public AActor, public IPickup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TEnumAsByte<Item> Type;

public:	
	virtual void Pickup(class AStoryPlayerState *State) override;
};
