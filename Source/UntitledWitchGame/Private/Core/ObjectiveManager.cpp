// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/ObjectiveManager.h"

// Sets default values
AObjectiveManager::AObjectiveManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectiveManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObjectiveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

