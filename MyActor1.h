// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor1.generated.h"

UCLASS()
class NBCTEST0108_2_API AMyActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// 현재 위치
	FVector CurrentPosition;

	// 이동 횟수
	int32 MoveCount;

	// 최대 이동 횟수
	int32 MaxMoves;

	// 랜덤으로 0 또는 1을 반환하는 함수
	int32 Step() const;
};