// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WaypointMarker.h"

UWaypointMarker::UWaypointMarker() {
	SetDrawAtDesiredSize(true);
	SetWidgetSpace(EWidgetSpace::Screen);
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UWaypointMarker::InitWidget() {
	Super::InitWidget();

	if (Widget) {

	}
}