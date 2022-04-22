// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpRequestObject.h"
#include "Json.h"
#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "Interfaces/IHttpResponse.h"

void UHttpRequestObject::StartTimerRequest()
{
	RequestOntheServer();
}



void UHttpRequestObject::RequestOntheServer()
{
	LoginApiPath= TEXT("https://jsonplaceholder.typicode.com/posts");
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this,&ThisClass::OnResponseReceived);
	Request->SetURL(LoginApiPath); 
	Request->SetVerb("GET");
	Request->ProcessRequest(); 

}
void UHttpRequestObject::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	
	if(bWasSuccessful)
	{
		TSharedPtr<FJsonObject> ResponsObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
		FJsonSerializer::Deserialize(Reader,ResponsObject);
		TArray<TSharedPtr<FJsonValue>> ArrString = ResponsObject->GetArrayField("id");
		for(auto a: ArrString)
		{
			GEngine->AddOnScreenDebugMessage(-1,10.f,
			FColor::MakeRandomColor(), FString::Printf(TEXT("id=%s"), *a.Get()->AsString()));
		}
	}
}
