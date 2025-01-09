// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor1::AMyActor1()
{
	PrimaryActorTick.bCanEverTick = true; // Tick Ȱ��ȭ

	// �ʱ�ȭ
	CurrentPosition = FVector(0.0f, 0.0f, 0.0f);
	MoveCount = 0;
	MaxMoves = 10;
}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();

	// �α� ���
	UE_LOG(LogTemp, Log, TEXT("AMyActor1 spawned at position: X: %.0f, Y: %.0f, Z: %.0f"), 
		CurrentPosition.X, CurrentPosition.Y, CurrentPosition.Z);
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �̵� ���� ����
	if (MoveCount >= MaxMoves)
	{
		
		UE_LOG(LogTemp, Log, TEXT("AMyActor1 has completed all moves."));
		PrimaryActorTick.bCanEverTick = false; // Tick ��Ȱ��ȭ
		return;
	}
	
		// ���� �̵� �Ÿ�
		int32 DeltaX = Step();
		int32 DeltaY = Step();
		

		// ���ο� ��ġ ���
		CurrentPosition.X += DeltaX;
		CurrentPosition.Y += DeltaY;
		

		// ���� ��ġ ������Ʈ
		SetActorLocation(CurrentPosition);

		// ���� ��ġ �α� ���
		UE_LOG(LogTemp, Log, TEXT("Move %d: X: %.0f, Y: %.0f, Z: %.0f"),
			MoveCount, CurrentPosition.X, CurrentPosition.Y, CurrentPosition.Z);

		// �̵� Ƚ�� ����
		MoveCount++;
	
}

// �������� 0 �Ǵ� 1�� ��ȯ�ϴ� �Լ�
int32 AMyActor1::Step() const
{
	return FMath::RandRange(0, 1); 
}
