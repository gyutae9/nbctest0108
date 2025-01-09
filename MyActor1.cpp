// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor1::AMyActor1()
{
	PrimaryActorTick.bCanEverTick = true; // Tick 활성화

	// 초기화
	CurrentPosition = FVector(0.0f, 0.0f, 0.0f);
	MoveCount = 0;
	MaxMoves = 10;
}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();

	// 로그 출력
	UE_LOG(LogTemp, Log, TEXT("AMyActor1 spawned at position: X: %.0f, Y: %.0f, Z: %.0f"), 
		CurrentPosition.X, CurrentPosition.Y, CurrentPosition.Z);
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 이동 종료 조건
	if (MoveCount >= MaxMoves)
	{
		
		UE_LOG(LogTemp, Log, TEXT("AMyActor1 has completed all moves."));
		PrimaryActorTick.bCanEverTick = false; // Tick 비활성화
		return;
	}
	
		// 랜덤 이동 거리
		int32 DeltaX = Step();
		int32 DeltaY = Step();
		

		// 새로운 위치 계산
		CurrentPosition.X += DeltaX;
		CurrentPosition.Y += DeltaY;
		

		// 엑터 위치 업데이트
		SetActorLocation(CurrentPosition);

		// 현재 위치 로그 출력
		UE_LOG(LogTemp, Log, TEXT("Move %d: X: %.0f, Y: %.0f, Z: %.0f"),
			MoveCount, CurrentPosition.X, CurrentPosition.Y, CurrentPosition.Z);

		// 이동 횟수 증가
		MoveCount++;
	
}

// 랜덤으로 0 또는 1을 반환하는 함수
int32 AMyActor1::Step() const
{
	return FMath::RandRange(0, 1); 
}
