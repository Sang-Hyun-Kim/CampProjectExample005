// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor11.h"

// Sets default values
AMyActor11::AMyActor11()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called when the game starts or when spawned
void AMyActor11::BeginPlay()
{
	Super::BeginPlay();
	TotalDistance = 0.0;
	SetActorLocation({0,0,150});

	//GetWorld()->GetTimerManager().SetTimer(
	//	handle,
	//	FTimerDelegate::CreateLambda(
	//		[&]()
	//		{
	//			Move();
	//		}
	//	),
	//	3.0f,
	//	true
	//);

	Move();
}

// Called every frame
void AMyActor11::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Display, TEXT("Tick"));
}

void AMyActor11::Move()
{
	for (int i = 0; i < 10; ++i)
	{
		UE_LOG(LogTemp, Display, TEXT("Move"));
		double curX = GetActorLocation().X;
		double curY = GetActorLocation().Y;
		double curZ = GetActorLocation().Z;
		double nextX = curX + Step();
		double nextY = curY + Step();
		
		double distance = Distance({curX,curY}, {nextX,nextY});
		SetActorLocation({nextX,nextY,curZ});
		UE_LOG(LogTemp, Display, TEXT("Current Location: (%f,%f)"), nextX,nextY);
		UE_LOG(LogTemp, Display, TEXT("Moved distance: %f"),distance);
		CreateEvent();
		
	}
	
	UE_LOG(LogTemp, Display, TEXT("TotalDistance moved: %f"), TotalDistance);
	UE_LOG(LogTemp, Warning, TEXT("TotalEvent Occured: %d"),TotalEvent);
	
	
}

int32_t AMyActor11::Step()
{

	auto Randrange = FMath::FRandRange(0.0, 2.0);
	
	return static_cast<int32_t>(Randrange);
}

double AMyActor11::Distance(const FVector2D& curV, const FVector2D& nextV)
{
	double distance
		= FMath::Sqrt(FMath::Square((nextV.X - curV.X)) + FMath::Square((nextV.Y - curV.Y)));
	TotalDistance += distance;
	return distance;
}

void AMyActor11::CreateEvent()
{
	int32_t Randrange = FMath::FRandRange(0.0, 2.0);
	if (Randrange % 2)
	{
		TotalEvent++;
		UE_LOG(LogTemp, Warning, TEXT("EventOccured!!"));
	}
	return;
}

