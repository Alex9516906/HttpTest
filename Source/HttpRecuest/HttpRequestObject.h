// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HttpRequestObject.generated.h"

class IHttpResponse;
class IHttpRequest;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FTransformData 
{
	GENERATED_BODY()
  
	UPROPERTY()
	FTransform BuildTransform;
	UPROPERTY()
	float FloorSize;
	UPROPERTY()
	FString Mat;
};
	
UCLASS()
class HTTPRECUEST_API UHttpRequestObject : public UObject
{
	GENERATED_BODY()

public:
	void StartTimerRequest();
	FTimerHandle Timer;
	UPROPERTY()
	FString LoginApiPath;

	void OnResponseReceived(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> Shared, TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> SharedPtr, bool bArg);
	UFUNCTION()
	void RequestOntheServer();

	UPROPERTY(BlueprintReadWrite)
	FTransformData DateOne;
};
