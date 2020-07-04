// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interactables/Openable.h"
#include "Placeables/Pickups/Items.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class UNTITLEDWITCHGAME_API ADoor : public AActor, public IOpenable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TEnumAsByte<Item> Key;
	
public:
	virtual void Open(class AStoryPlayerState *State) override;
};
