// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingDataAsset.h"
#include "GameFramework/GameMode.h"
#include "HttpgameMode.generated.h"

class UHttpRequestObject;
/**
 * 
 */
UCLASS()
class HTTPRECUEST_API AHttpgameMode : public AGameMode
{
	GENERATED_BODY()

	AHttpgameMode();

	virtual void BeginPlay() override;
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UHttpRequestObject* obj;

private:
	void Construction(TArray<UClass*> Actors, TArray<FTransform*> Transforms, TArray<UStaticMeshComponent*> Meshes, TArray<UMaterialInterface*> Materials);

	TArray<UBuildingDataAsset> BuildingDataAssets;
};
