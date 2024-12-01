// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TencentCoursePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TENCENTCOURSE_API ATencentCoursePlayerState : public APlayerState
{
	GENERATED_BODY()
	ATencentCoursePlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UFUNCTION()
	int AddPlayerScore(int AddScore);

private:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = "OnRep_PlayerScore")
	int PlayerScore {0};

	UFUNCTION()
	void OnRep_PlayerScore(int32 OldScore);
};
