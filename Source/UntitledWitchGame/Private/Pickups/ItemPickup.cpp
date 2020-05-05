// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/ItemPickup.h"
#include "StoryPlayerState.h"

// Sets default values
AItemPickup::AItemPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AItemPickup::Pickup(AStoryPlayerState *State) {
	State->AddItem(Type);
	UE_LOG(LogTemp, Warning, TEXT("Picked up an item!"));
}