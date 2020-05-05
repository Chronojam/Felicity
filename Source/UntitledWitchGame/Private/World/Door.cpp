// Fill out your copyright notice in the Description page of Project Settings.


#include "World/Door.h"
#include "StoryPlayerState.h"


void ADoor::Open(AStoryPlayerState *State) {
	// Check if we're carrying the key.
	if (State->Items.Contains(Key)) {
		// Set to open or whatever.
		UE_LOG(LogTemp, Warning, TEXT("Opened Door:"));
		// Just destroy the door for now.
		Destroy();
	}
	// Otherwise do nothing
}