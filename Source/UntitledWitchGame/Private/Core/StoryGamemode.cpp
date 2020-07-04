// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/StoryGamemode.h"
#include "Core/StoryController.h"
#include "Core/StoryCharacter.h"
#include "Core/StoryPlayerState.h"

AStoryGamemode::AStoryGamemode() {
	PlayerControllerClass = AStoryController::StaticClass();
	PlayerStateClass = AStoryPlayerState::StaticClass();
	DefaultPawnClass = AStoryCharacter::StaticClass();
}