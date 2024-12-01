// Fill out your copyright notice in the Description page of Project Settings.


#include "TencentCoursePlayerState.h"

#include "Net/UnrealNetwork.h"


ATencentCoursePlayerState::ATencentCoursePlayerState()
{
}

void ATencentCoursePlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATencentCoursePlayerState, PlayerScore);
}

int ATencentCoursePlayerState::AddPlayerScore(int AddScore)
{
	if (AddScore == 0)
	{
		return PlayerScore;
	}

	PlayerScore += AddScore;
	return PlayerScore;
}


void ATencentCoursePlayerState::OnRep_PlayerScore(int32 OldScore)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("%s Score [%d->%d]"), *GetName(), OldScore, PlayerScore));
}
