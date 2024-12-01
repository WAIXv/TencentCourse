// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomShootTargetSpawner.generated.h"

class AShootTarget;
class UBoxComponent;

UCLASS()
class TENCENTCOURSE_API ARandomShootTargetSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomShootTargetSpawner();

	bool SpawnShootTargets(UINT InTotalShootTarget, const FVector& InLocation);

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AShootTarget> ShootTargetClass;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> RandomBoxComponent;

	UPROPERTY()
	TArray<TObjectPtr<AShootTarget>> ShootTargets;

	UINT TotalShootTarget;
};
