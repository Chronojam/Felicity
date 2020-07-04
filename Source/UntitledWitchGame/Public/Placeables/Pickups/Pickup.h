// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UPickup : public UInterface
{
	GENERATED_BODY()

};

class IPickup {
	GENERATED_BODY()

public:
	virtual void Pickup(class AStoryPlayerState *State) PURE_VIRTUAL(IPickup::Pickup, );
};
