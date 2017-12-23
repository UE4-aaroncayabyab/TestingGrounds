// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TestingGroundsGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

ATestingGroundsGameMode::ATestingGroundsGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}

void ATestingGroundsGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void ATestingGroundsGameMode::AddToPool(ANavMeshBoundsVolume * VolumeToAdd)
{
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}
