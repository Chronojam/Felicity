// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/HealthPickup.h"
#include "StoryPlayerState.h"

// Sets default values
AHealthPickup::AHealthPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set me properly in BP.
	HealAmount = 0;
}
void AHealthPickup::Pickup(AStoryPlayerState *State) {
	// Give the player some health
	State->AlterHealth(HealAmount);
}