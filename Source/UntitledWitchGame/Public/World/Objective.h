// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Objective.generated.h"


// Emit me when this objective is updated.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectiveCompleted, AObjective*, Completed);


UCLASS()
class UNTITLEDWITCHGAME_API AObjective : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjective();

	UPROPERTY(EditAnywhere)
	bool Active;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere)
	AObjective* Next;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FOnObjectiveCompleted OnObjectiveCompleted;

	UFUNCTION(BlueprintCallable)
	virtual void CompleteObjective();
};
