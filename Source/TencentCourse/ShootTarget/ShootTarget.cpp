// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootTarget.h"

#include "TencentCourse/FirstPerson/TencentCourseCharacter.h"
#include "TencentCourse/FirstPerson/TencentCourseProjectile.h"

class ATencentCourseProjectile;

AShootTarget::AShootTarget()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(MeshComponent);

	MeshComponent->OnComponentHit.AddDynamic(this, &AShootTarget::OnMeshComponentHit);
}

void AShootTarget::OnMeshComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ATencentCourseProjectile* Projectile = Cast<ATencentCourseProjectile>(OtherActor);
	if (Projectile == nullptr) { return; }

	APawn* ProjectileInstigator = Projectile->GetInstigator();
	if (ProjectileInstigator == nullptr) { return; }

	ATencentCourseCharacter* PlayerCharacter = Cast<ATencentCourseCharacter>(ProjectileInstigator);
	if (PlayerCharacter == nullptr) { return; }
	
	PlayerCharacter->AddScore(GainScore);

	if (IncreaseHitCount())
	{
		Destroy(true);
	}
}

void AShootTarget::SetIsAceTarget(bool In_bIsAceTarget)
{
	if (In_bIsAceTarget == bIsAceTarget) { return; }

	OnChangeIsAceTargetEvent(In_bIsAceTarget);
	bIsAceTarget = In_bIsAceTarget;
	GainScore = bIsAceTarget ? GainScore * 2 : GainScore / 2;
}

bool AShootTarget::IncreaseHitCount()
{
	HitCount++;
	if (HitCount == 1)
	{
		SetActorScale3D( GetActorScale3D() * FVector(3.f) );
		return false;
	}

	return true;
}

ATencentCourseCharacter* AShootTarget::GetPlayerCharacter() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const APlayerController* PlayerController = World->GetFirstPlayerController())
		{
			if (APawn* PlayerPawn = PlayerController->GetPawn())
			{
				return Cast<ATencentCourseCharacter>(PlayerPawn);
			}
		}
	}

	return nullptr;
}

