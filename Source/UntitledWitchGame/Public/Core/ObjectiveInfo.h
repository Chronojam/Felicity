// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectiveInfo.generated.h"

UCLASS(BlueprintType)
class UNTITLEDWITCHGAME_API UObjectiveInfo : public UObject {
	GENERATED_BODY()

public:
	UObjectiveInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UObjectiveInfo* Next;
};