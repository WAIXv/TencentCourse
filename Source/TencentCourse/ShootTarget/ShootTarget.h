// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootTarget.generated.h"

class ATencentCourseCharacter;

UCLASS()
class TENCENTCOURSE_API AShootTarget : public AActor
{
	GENERATED_BODY()
	AShootTarget();

	UFUNCTION()
	void OnMeshComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	void SetIsAceTarget(bool In_bIsAceTarget);
	
protected:
	bool IncreaseHitCount();
	ATencentCourseCharacter* GetPlayerCharacter() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnChangeIsAceTargetEvent(bool In_bIsAceTarget);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditAnywhere)
	int GainScore {2};

	bool bIsAceTarget {false};
	int HitCount {0};
};
