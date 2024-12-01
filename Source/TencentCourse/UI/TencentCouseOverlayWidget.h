// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TencentCouseOverlayWidget.generated.h"

UCLASS()
class TENCENTCOURSE_API UTencetCourseOverlayWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent)
	void OnAddCurrentScore(int NewScore);
};
