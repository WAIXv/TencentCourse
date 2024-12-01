// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TencentCourseHUD.generated.h"

class UTencetCourseOverlayWidget;
/**
 * 
 */
UCLASS()
class TENCENTCOURSE_API ATencentCourseHUD : public AHUD
{
	GENERATED_BODY()

public:
	void InitOverlay(APlayerController* PC, APlayerState* PS);

	UPROPERTY()
	TObjectPtr<UTencetCourseOverlayWidget> OverlayWidget;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UTencetCourseOverlayWidget> OverlayWidgetClass;
};
