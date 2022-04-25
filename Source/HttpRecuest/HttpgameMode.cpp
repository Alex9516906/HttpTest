// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpgameMode.h"
#include "HttpRequestObject.h"
#include "Engine/ObjectLibrary.h"
#include "EngineUtils.h"

AHttpgameMode::AHttpgameMode()
{
	ConstructorHelpers::FObjectFinder<UBuildingDataAsset> BuildDataAsset(TEXT
		("BuildingDataAsset'/Game/Content/BuildingDataAssets/CubeDataAsset.CubeDataAsset'"));
	
	if(BuildDataAsset.Succeeded())
	{
		UE_LOG(LogTemp, Display, TEXT("Name = %s"), *BuildDataAsset.Object->GetName());
	}
	
	
	/*auto ObjectLibrary = UObjectLibrary::CreateLibrary(UWorld::StaticClass(), false, false);
	ObjectLibrary->LoadAssetDataFromPath(TEXT("/Game/Content/BuildingDataAssets"));
	TArray<FAssetData> AssetDatas;
	ObjectLibrary->GetAssetDataList(AssetDatas);
	UE_LOG(LogTemp, Warning, TEXT("Found maps: %d"), AssetDatas.Num());*/

	
	/*TArray<UObject*> MeshAssets;
	EngineUtils::FindOrLoadAssetsByPath(TEXT("D:/Projects/My Games/Unreal Engine/Https/Content/BuildingDataAssets/"), MeshAssets, EngineUtils::ATL_Regular);
	UE_LOG(LogTemp, Warning, TEXT("Length = %i"), MeshAssets.Num());
	for (auto asset : MeshAssets)
	{
		auto Data = Cast<UBuildingDataAsset>(asset);
		if (!Data) return;

		UE_LOG(LogTemp, Display, TEXT("Name = %s"), *Data->GetName());
	}*/
}

void AHttpgameMode::BeginPlay()
{
	Super::BeginPlay();

	obj = NewObject<UHttpRequestObject>(UHttpRequestObject::StaticClass());
	if(obj)
	{
		obj->StartTimerRequest();
	}


}

void AHttpgameMode::Construction(TArray<UClass*> Actors, TArray<FTransform*> Transforms,
	TArray<UStaticMeshComponent*> Meshes, TArray<UMaterialInterface*> Materials)
{
	if(Actors.Num() != Transforms.Num() ||
	Actors.Num() != Materials.Num() ||
	Actors.Num() != Materials.Num() ||
	!GetWorld()) return;
	
	for (int i = 0; i < Actors.Num(); ++i)
	{
		const auto SpawnActor = GetWorld()->SpawnActor(Actors[i], Transforms[i]);
		
		Meshes[i]->SetMaterial(0, Materials[i]);
		SpawnActor->AttachToComponent(Meshes[i], FAttachmentTransformRules::KeepRelativeTransform);
	}
}
