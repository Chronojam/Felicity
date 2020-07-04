// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectiveManager.generated.h"

UCLASS()
class UNTITLEDWITCHGAME_API AObjectiveManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectiveManager();

	// A list of all objectives for this level.
	// Set me in BP
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UObjectiveInfo*> Objectives;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//void AddObjective(struct FObjectiveInfo o);
};
