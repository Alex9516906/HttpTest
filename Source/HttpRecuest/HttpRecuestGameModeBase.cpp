// Copyright Epic Games, Inc. All Rights Reserved.


#include "HttpRecuestGameModeBase.h"

void AHttpRecuestGameModeBase::Construction(TArray<UClass*> Actors, TArray<FTransform*> Transforms,
	TArray<UStaticMeshComponent*> Meshes, TArray<UMaterialInterface*> Materials)
{
	if(Actors.Num() != Transforms.Num() ||
		Actors.Num() != Materials.Num() ||
		Actors.Num() != Materials.Num()) return;
	
	for (int i = 0; i < Actors.Num(); ++i)
	{
		const auto SpawnActor = UWorld::SpawnActor(Actors[i], Transforms[i]);
		
		Meshes[i]->SetMaterial(0, Materials[i]);
		SpawnActor->AttachToComponent(Meshes[i], FAttachmentTransformRules::KeepRelativeTransform);
	}
}
