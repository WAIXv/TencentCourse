// Copyright Epic Games, Inc. All Rights Reserved.

#include "TencentCourseGameMode.h"

#include "TencentCourse/ShootTarget/RandomShootTargetSpawner.h"
#include "UObject/ConstructorHelpers.h"

ATencentCourseGameMode::ATencentCourseGameMode()
	: Super()
{
	

}

void ATencentCourseGameMode::BeginPlay()
{

}

void ATencentCourseGameMode::SpawnShootTargetsAtLocation(int TargetCount, const FVector& Location)
{
	if (IsValid(ShootTargetSpawnerClass) || TargetCount > 0)
	{
		FActorSpawnParameters SpawnParams;
		FRotator Rotation = FRotator::ZeroRotator;
		
		ARandomShootTargetSpawner* Spawner = GetWorld()->SpawnActor<ARandomShootTargetSpawner>(
			ShootTargetSpawnerClass, Location, Rotation, SpawnParams);
		Spawner->SpawnShootTargets(10, Location);
	}
}
