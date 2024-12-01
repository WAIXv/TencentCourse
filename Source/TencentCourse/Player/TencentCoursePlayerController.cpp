// Copyright Epic Games, Inc. All Rights Reserved.


#include "TencentCoursePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "TencentCoursePlayerState.h"
#include "Engine/LocalPlayer.h"
#include "TencentCourse/UI/TencentCourseHUD.h"


void ATencentCoursePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	if (auto Hud = GetHUD())
	{
		if (auto HUD = Cast<ATencentCourseHUD>(Hud))
		{
			HUD->InitOverlay(this, GetPlayerState<ATencentCoursePlayerState>());
		}
	}
}
