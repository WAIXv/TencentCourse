// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TencentCourseGameMode.generated.h"

class ARandomShootTargetSpawner;

UCLASS(minimalapi)
class ATencentCourseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATencentCourseGameMode();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SpawnShootTargetsAtLocation(int TargetCount, const FVector& Location);

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ARandomShootTargetSpawner> ShootTargetSpawnerClass;

	FVector SpawnLocation;
};



