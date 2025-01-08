// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyActor11.generated.h"

UCLASS()
class CAMPPROJECT_API AMyActor11 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor11();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move();
	int32_t Step();/*
	FTimerHandle handle;*/
	double Distance(const FVector2D& curV, const FVector2D& nextV);
	void CreateEvent();
private:
	double TotalDistance;
	int32_t TotalEvent;
};
