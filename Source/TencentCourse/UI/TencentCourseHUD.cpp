// Fill out your copyright notice in the Description page of Project Settings.


#include "TencentCourseHUD.h"

#include "TencentCouseOverlayWidget.h"
#include "Blueprint/UserWidget.h"

void ATencentCourseHUD::InitOverlay(APlayerController* PC, APlayerState* PS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class unitialized, please fill out BP_TencetCourseHUD"))

	OverlayWidget = CreateWidget<UTencetCourseOverlayWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget->AddToViewport();
}
