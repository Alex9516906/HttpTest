// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	virtual void BeginPlay() override;
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UHttpRequestObject* obj;
};
