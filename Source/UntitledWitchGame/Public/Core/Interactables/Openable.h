// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Openable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UOpenable : public UInterface
{
	GENERATED_BODY()

};

class IOpenable {
	GENERATED_BODY()

public:
	virtual void Open(class AStoryPlayerState *State) PURE_VIRTUAL(IOpenable::Open, );
};
