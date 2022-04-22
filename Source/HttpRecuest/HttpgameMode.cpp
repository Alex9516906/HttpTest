// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpgameMode.h"

#include "HttpRequestObject.h"

void AHttpgameMode::BeginPlay()
{
	Super::BeginPlay();

	obj = NewObject<UHttpRequestObject>(UHttpRequestObject::StaticClass());
	if(obj)
	{
		obj->StartTimerRequest();
	}
}
