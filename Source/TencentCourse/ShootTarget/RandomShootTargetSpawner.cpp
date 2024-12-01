// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomShootTargetSpawner.h"
#include "ShootTarget.h"
#include "Components/BoxComponent.h"

ARandomShootTargetSpawner::ARandomShootTargetSpawner()
{
	USceneComponent* RootSceneComponent = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(RootSceneComponent);

	USceneComponent* ChildSceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	ChildSceneComponent->SetupAttachment(RootSceneComponent);
	
	RandomBoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	RandomBoxComponent->SetupAttachment(ChildSceneComponent);
	// SetRootComponent(RandomBoxComponent);
}


bool ARandomShootTargetSpawner::SpawnShootTargets(UINT InTotalShootTarget, const FVector& InLocation)
{
	if (!IsValid(ShootTargetClass) || InTotalShootTarget == 0)
	{
		return false;
	}

	if (!IsValid(RandomBoxComponent) || RandomBoxComponent->GetScaledBoxExtent() == FVector::Zero())
	{
		return false;
	}

	SetActorLocation(InLocation);

	UINT AceTargetCount = InTotalShootTarget / 3;
	TArray<UINT> AceTargetIndexs;
	for (UINT i = 0; i < AceTargetCount;)
	{
		int RandomIndex = FMath::RandRange(0, InTotalShootTarget);
		if (AceTargetIndexs.Contains(RandomIndex))
		{
			continue;
		}
		AceTargetIndexs.Emplace(RandomIndex);
		++i;
	}

	FVector RandomBoxExtend = RandomBoxComponent->GetScaledBoxExtent();
	for (UINT i = 0; i < InTotalShootTarget; ++i)
	{
		FVector ShootTargetLocation{
			InLocation.X + FMath::RandRange(-RandomBoxExtend.X, RandomBoxExtend.X),
			InLocation.Y + FMath::RandRange(-RandomBoxExtend.Y, RandomBoxExtend.Y),
			InLocation.Z + FMath::RandRange(-RandomBoxExtend.Z, RandomBoxExtend.Z)};
		FRotator ShootTargetRotation = FRotator::ZeroRotator;

		FActorSpawnParameters SpawnParams;
		if (UWorld* World = GetWorld())
		{
			auto* ShootTarget = World->SpawnActor<AShootTarget>(ShootTargetClass, ShootTargetLocation, ShootTargetRotation);
			ShootTarget->SetIsAceTarget(AceTargetIndexs.Contains(i));
		}
	}

	return true;
}

