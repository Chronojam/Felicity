// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryPlayerState.h"
#include "Pickups/Items.h"
#include "World/ObjectiveInfo.h"


void AStoryPlayerState::BeginPlay() {
	Super::BeginPlay();

	Health = 25.0f;
	MaxHealth = 200.0f;

	OnStateChanged.Broadcast(this);
}

void AStoryPlayerState::AlterHealth(float a) {
	Health += a;
	if (Health > MaxHealth) {
		Health = MaxHealth;
	}

	// Tell all the listeners that the health has been updated.
	OnStateChanged.Broadcast(this);
}
void AStoryPlayerState::AddItem(Item item) {
	this->Items.AddUnique(item);

	// Tell all listeners that we've picked something up.
	OnStateChanged.Broadcast(this);
}