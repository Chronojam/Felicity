// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "WaypointMarker.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UNTITLEDWITCHGAME_API UWaypointMarker : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UWaypointMarker();

	virtual void InitWidget() override;
	
};
