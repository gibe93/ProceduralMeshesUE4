#include "ProceduralMeshActor.h"
#include "ProceduralMeshComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "GameFramework/Actor.h"

AProceduralMeshActor::AProceduralMeshActor()
{
	PrimaryActorTick.bCanEverTick = true;
	m_fAccumulator = 0.0f;
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
	SelectedVertex = nullptr;
	SelectedVertexEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SelectedVertexEffect"));
	SetRootComponent(ProceduralMesh);
	SelectedVertexEffect->AttachTo(ProceduralMesh);
	ProceduralMesh->bUseAsyncCooking = true;
}

void AProceduralMeshActor::BeginPlay()
{
	Super::BeginPlay();
	SelectedVertexEffect->SetVisibility(false);
	GenerateProceduralMesh();
}

void AProceduralMeshActor::GenerateTriangle(int32 Vertex1, int32 Vertex2, int32 Vertex3)
{
	Triangles.Add(Vertex1);
	Triangles.Add(Vertex2);
	Triangles.Add(Vertex3);
}

void AProceduralMeshActor::GenerateProceduralMesh()
{
	LowerBackLeft = FVector(0, -100, 0);       // lower left - 0
	UpperBackLeft = FVector(0, -100, 100);     // upper left - 1
	LowerBackRight = FVector(0, 100, 0);       // lower right - 2 
	UpperBackRight = FVector(0, 100, 100);     // upper right - 3

	LowerFrontLeft = FVector(100, -100, 0);    // lower front left - 4
	UpperFrontLeft = FVector(100, -100, 100);  // upper front left - 5
	UpperFrontRight = FVector(100, 100, 100);  // upper front right - 6
	LowerFrontRight = FVector(100, 100, 0);    // lower front right - 7

	Vertices.Add(LowerBackLeft);
	Vertices.Add(UpperBackLeft);
	Vertices.Add(LowerBackRight);
	Vertices.Add(UpperBackRight);

	Vertices.Add(LowerFrontLeft);
	Vertices.Add(UpperFrontLeft);
	Vertices.Add(UpperFrontRight);
	Vertices.Add(LowerFrontRight);

	FaceBot = FCubeFace(&Vertices[0], &Vertices[2], &Vertices[4], &Vertices[7]);
	FaceTop = FCubeFace(&Vertices[1], &Vertices[3], &Vertices[5], &Vertices[6]);
	FaceLeft = FCubeFace(&Vertices[0], &Vertices[4], &Vertices[1], &Vertices[5]);
	FaceRight = FCubeFace(&Vertices[2], &Vertices[7], &Vertices[3], &Vertices[6]);

	// Back face
	GenerateTriangle(0, 2, 3);
	GenerateTriangle(3, 1, 0);

	// Left face 
	GenerateTriangle(0, 1, 4);
	GenerateTriangle(4, 1, 5);

	// Front face 
	GenerateTriangle(4, 5, 7);
	GenerateTriangle(7, 5, 6);

	// Right face 
	GenerateTriangle(7, 6, 3);
	GenerateTriangle(3, 2, 7);

	// Top face
	GenerateTriangle(1, 3, 5);
	GenerateTriangle(6, 5, 3);

	// Bottom face
	GenerateTriangle(2, 0, 4);
	GenerateTriangle(4, 7, 2);


	TArray<FLinearColor> VertexColors;
	VertexColors.Add(FLinearColor(1.f, 0.f, 1.f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	VertexColors.Add(FLinearColor(0.5f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(0.5f, 0.f, 0.5f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(1.f, 0.5f, 0.5f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 1.f));

	ProceduralMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), VertexColors, TArray<FProcMeshTangent>(), true);
}

void AProceduralMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::Zero))
	{
		SelectedVertex = &Vertices[0];
	}
	else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::One))
	{
		SelectedVertex = &Vertices[1];
	}
	else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::Two))
	{
		SelectedVertex = &Vertices[2];
	}
	else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::Three))
	{
		SelectedVertex = &Vertices[3];
	}
	else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::Four))
	{
		SelectedVertex = &Vertices[4];
	}
	else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::Five))
	{
		SelectedVertex = &Vertices[5];
	}
	else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::Six))
	{
		SelectedVertex = &Vertices[6];
	}
	else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::Seven))
	{
		SelectedVertex = &Vertices[7];
	}
	if (SelectedVertex != nullptr)
	{
		if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::I)) SelectedVertex->Z += 20 * DeltaTime;
		else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::K)) SelectedVertex->Z -= 20 * DeltaTime;
		else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::L)) SelectedVertex->Y += 20 * DeltaTime;
		else if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::J)) SelectedVertex->Y -= 20 * DeltaTime;

		SelectedVertexEffect->SetVisibility(true);
		SelectedVertexEffect->SetRelativeLocation(*SelectedVertex);
	}
	m_fAccumulator += DeltaTime;

	ProceduralMesh->UpdateMeshSection(0, Vertices, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>());

	//}
}

