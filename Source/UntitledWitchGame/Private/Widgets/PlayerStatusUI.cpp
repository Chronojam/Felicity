// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/PlayerStatusUI.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Pickups/Items.h"
#include "StoryPlayerState.h"


void UPlayerStatusUI::OnStateChanged(AStoryPlayerState *State) {

	// Calculate player health
	auto percentHealth = (State->Health / State->MaxHealth);
	HealthIndicator->SetPercent(percentHealth);

	// Decide if we've got whatever runes, should move this
	// to a new delegate, this is sloppy.
	if (State->Items.Contains(Item::RuneKey_Moon)) {
		Moon_Rune->SetColorAndOpacity(FLinearColor(0, 0, 1, 1));
	}
	if (State->Items.Contains(Item::RuneKey_Sun)) {
		Sun_Rune->SetColorAndOpacity(FLinearColor(1, 1, 0, 1));
	}
}