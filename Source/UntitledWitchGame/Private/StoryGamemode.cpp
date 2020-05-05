// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryGamemode.h"
#include "StoryController.h"
#include "StoryCharacter.h"
#include "StoryPlayerState.h"

AStoryGamemode::AStoryGamemode() {
	PlayerControllerClass = AStoryController::StaticClass();
	PlayerStateClass = AStoryPlayerState::StaticClass();
	DefaultPawnClass = AStoryCharacter::StaticClass();
}