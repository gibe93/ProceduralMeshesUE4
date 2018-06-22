#include "ProceduralMeshActor.h"
#include "ProceduralMeshComponent.h"
#include "GameFramework/Actor.h"

AProceduralMeshActor::AProceduralMeshActor()
{
	PrimaryActorTick.bCanEverTick = true;

	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
	SetRootComponent(ProceduralMesh);
	ProceduralMesh->bUseAsyncCooking = true;
}

void AProceduralMeshActor::BeginPlay()
{
	Super::BeginPlay();
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
	if(GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::O))
	{
		for(FVector* V : FaceLeft.Vertices)
		{
			V->Y -= 10 * DeltaTime;
		}
		ProceduralMesh->UpdateMeshSection(0, Vertices, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>());
	
	}
}

