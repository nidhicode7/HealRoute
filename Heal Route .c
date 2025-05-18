#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 500
struct patientStucture {
	char name[30];
	int id,department,phone,age;
} patientStuctureArray[100];
struct Doctor {
	char position[MAX_STR_LEN], expertise[MAX_STR_LEN];
	char route[MAX_STR_LEN*MAX_STR_LEN], emergencyDoctor[MAX_STR_LEN], nonEmergencyDoctor[MAX_STR_LEN];
} doctors[10];
int admittedPatientsCount=0, doctor, floorNumber, deptId, patientId, emergency;
void loadPolicies();
void loadDoctorsArray();
void patientVisit();
void getMedicalAttention(int i);
void view(int i);
void getDeptNameById(int i);
void listOutDeptsWithIds();
void showDeptRoute(int i);
int main() {
	loadPolicies();
	loadDoctorsArray();
	int loop=1;
	while(loop!=0) {
		printf("\n==============================================================================================================\n");
		printf("Number of Patients admitted are : %d \n",admittedPatientsCount);
		printf("What would you like to do today?\n");
		printf("Enter '0' for Exit \n");
		printf("Enter '1' for Get medical attention \n");
		printf("Enter '2' for Visit a patient \n");
		printf("Enter '3' for Route of Department or place in hospital \n");
		printf("Enter your choice: ");
		scanf("%d", &loop);
		if(loop==0) {
			break;
		} else if(loop==1) {
			getMedicalAttention(++admittedPatientsCount);
		} else if(loop==2) {
			patientVisit();
		} else if(loop==3) {
			listOutDeptsWithIds();
			printf("Enter the deptId for route from above list :");
			scanf("%d",&deptId);
			int validDept=0;
			while(validDept==0) {
				if (deptId < 1 || deptId > 10) {
					printf("Invalid choice. Please enter a number between 1 and 10.\n");
					validDept=0;
					printf("Again Enter the ID of the doctor you would like to view: ");
					scanf("%d",&deptId);
				} else {
					validDept=1;
				}
			}
			showDeptRoute(deptId);
			printf("\n\n");
		}
	}
	return 0;
}
void loadPolicies() {
	printf("\n======================Welcome to the hospital guide!======================\n");
	printf("Hospital Policies and Timings\n");
	printf("-----------------------------\n");
	printf("1. Appointments are mandatory. Walk-ins are not allowed.\n");
	printf("2. The hospital operates from 9:00 AM to 5:00 PM, Monday to Saturday.\n");
	printf("3. No outside food is allowed inside the hospital premises.\n");
	printf("4. Visitors are not allowed after 8:00 PM.\n");
	printf("5. Smoking and alcohol consumption are strictly prohibited on the hospital premises.\n");
	printf("6. Please cooperate with the hospital staff and follow the rules for a safe and healthy environment.\n");
}
void loadDoctorsArray() {
	strcpy(doctors[0].position, "Cardiologist");
	strcpy(doctors[0].expertise, "Heart Diseases");
	strcpy(doctors[0].route, "Go to 1st floor and then take the left corridor");
	strcpy(doctors[0].emergencyDoctor, "Emergency Dr Antony");
	strcpy(doctors[0].nonEmergencyDoctor, "Non Emergency Dr John");
	strcpy(doctors[1].position, "Neurologist");
	strcpy(doctors[1].expertise, "Brain and Nervous System");
	strcpy(doctors[1].route, "Go to 1st floor and take the right corridor");
	strcpy(doctors[1].emergencyDoctor, "Emergency Dr Kate");
	strcpy(doctors[1].nonEmergencyDoctor, "Non Emergency Dr Tony");
	strcpy(doctors[2].position, "Dermatologist");
	strcpy(doctors[2].expertise, "Skin Diseases");
	strcpy(doctors[2].route, "Go to 1st floor and take the center corridor");
	strcpy(doctors[2].emergencyDoctor, "Emergency Dr Oscar");
	strcpy(doctors[2].nonEmergencyDoctor, "Non Emergency Dr Janet");
	strcpy(doctors[3].position, "Gynecologist");
	strcpy(doctors[3].expertise, "Women's Reproductive Health");
	strcpy(doctors[3].route, "Go to 2nd floor and take the left corridor");
	strcpy(doctors[3].emergencyDoctor, "Emergency Dr Blaze");
	strcpy(doctors[3].nonEmergencyDoctor, "Non Emergency Dr Pankaj");
	strcpy(doctors[4].position, "Ophthalmologist");
	strcpy(doctors[4].expertise, "Eye Diseases");
	strcpy(doctors[4].route, "Go to 2nd floor and take the right corridor");
	strcpy(doctors[4].emergencyDoctor, "Emergency Dr Cristin");
	strcpy(doctors[4].nonEmergencyDoctor, "Non Emergency Dr Thomson");
	strcpy(doctors[5].position, "Orthopedic Surgeon");
	strcpy(doctors[5].expertise, "Bones, Joints, and Muscles");
	strcpy(doctors[5].route, "Go to 2nd floor and take the center corridor");
	strcpy(doctors[5].emergencyDoctor, "Emergency Dr Tina");
	strcpy(doctors[5].nonEmergencyDoctor, "Non Emergency Dr Nico ");
	strcpy(doctors[6].position, "ENT Specialist");
	strcpy(doctors[6].expertise, "Ear, Nose, and Throat");
	strcpy(doctors[6].route, "Go to 3rd floor and take the left corridor");
	strcpy(doctors[6].emergencyDoctor, "Emergency Dr Neel");
	strcpy(doctors[6].nonEmergencyDoctor, "Non Emergency Dr Napin");
	strcpy(doctors[7].position, "Urologist");
	strcpy(doctors[7].expertise, "Urinary System");
	strcpy(doctors[7].route, "Go to 3rd floor and take the right corridor");
	strcpy(doctors[7].emergencyDoctor, "Emergency Dr Charlie");
	strcpy(doctors[7].nonEmergencyDoctor, "Non Emergency Dr Peter");
	strcpy(doctors[8].position, "Psychiatrist");
	strcpy(doctors[8].expertise, "Mental Health");
	strcpy(doctors[8].route, "Go to 3rd floor and take the center corridor");
	strcpy(doctors[8].emergencyDoctor, "Emergency Dr Rishi");
	strcpy(doctors[8].nonEmergencyDoctor, "Non Emergency Dr Billie");
	strcpy(doctors[9].position, "General Practitioner");
	strcpy(doctors[9].expertise, "Primary Care");
	strcpy(doctors[9].route, "Go to 4th floor and take the left corridor");
	strcpy(doctors[9].emergencyDoctor, "Emergency Dr Newton");
	strcpy(doctors[9].nonEmergencyDoctor, "Non Emergency Dr Archemedes");
}

void patientVisit() {
    int patientId;
	printf("Enter the patient Id for visit(0-9) :");
	scanf("%d",&patientId);
    if(patientId==0){
        printf("go to floor 1 ROOM NO-123");
    }
    else if(patientId==1){
        printf("go to floor 2 ROOM NO-234");
    }
    else if(patientId==2){
        printf("go to floor 2 ROOM NO-234");
    }
    else if(patientId==3){
        printf("go to floor 3 ROOM NO-345");
    }
    else if(patientId==4){
        printf("go to floor 4 ROOM NO-401");
    }
    else if(patientId==5){
        printf("go to floor 5 ROOM NO-543");
    }
    if(patientId==6){
        printf("go to floor 1 ROOM no-196");
    }
    else if(patientId==7){
        printf("go to floor 2 ROOM no-287");
    }
    else if(patientId==8){
        printf("go to fllor 3 ROOM no-345");
    }
    else if(patientId==9){
        printf("go to floor 4 ROOM no-412");
    }
    else if (patientId!=0 & patientId!=1 & patientId!=2 & patientId!=3 & patientId!=4 & patientId!=5 & patientId!=6 & patientId!=7 & patientId!=8 & patientId!=9 ){
        printf("Enter valid patient Id try again.\n");
    }
}
void getMedicalAttention(int i) {
	patientStuctureArray[i].id=i;
	printf("Enter a patient Name : ");
	scanf("%s", patientStuctureArray[i].name);
	printf("Enter a patient age : ");
	scanf("%d", &patientStuctureArray[i].age);
	printf("Enter a patient mobile number : ");
	scanf("%d", &patientStuctureArray[i].phone);
	listOutDeptsWithIds();
	printf("Enter the ID of the doctor you would like to view: ");
	scanf("%d",&patientStuctureArray[i].department);
	int validDept=0;
	while(validDept==0) {
		if (patientStuctureArray[i].department < 1 || patientStuctureArray[i].department > 10) {
			printf("Invalid choice. Please enter a number between 1 and 10.\n");
			validDept=0;
			printf("Again Enter the ID of the doctor you would like to view: ");
			scanf("%d",&patientStuctureArray[i].department);
		} else {
			validDept=1;
		}
	}
	printf("Enter '1' for Emergency '0' for Normal / Non Emergency :");
	scanf("%d",&emergency);
	printf("Check your details \n");
	view(i);
	printf(" and consult ");
	if(emergency==1) {
		printf(" %s. \n\n", doctors[(patientStuctureArray[i].department-1)].emergencyDoctor);
	} else {
		printf(" %s. \n\n", doctors[(patientStuctureArray[i].department-1)].nonEmergencyDoctor);
	}
	printf("Enter '1' for confirm, '0' for re-enter the details : ");
	int checkStatus;
	scanf("%d", &checkStatus);
	if(checkStatus==1) {
		printf("-----Your details are successfully saved----- \n");
	} else {
		getMedicalAttention(i);
	}
}
void listOutDeptsWithIds() {
	printf("%-5s | %-20s | %-30s\n", "ID", "Department", "Area of Expertise");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < 10; i++) {
		printf("%-5d | %-20s | %-30s\n", i+1, doctors[i].position, doctors[i].expertise);
	}
	printf("-------------------------------------------------------------\n");
}
void view(int i) {
	printf("Patient Id : %d\n",i);
	printf("Name : ");
	puts(patientStuctureArray[i].name);
	printf("Phone Number : %d \nAge : %d \n",patientStuctureArray[i].phone,patientStuctureArray[i].age);
	printf("Department : %s \n", doctors[(patientStuctureArray[i].department-1)].position);
	showDeptRoute(patientStuctureArray[i].department);
}
void getDeptNameById(int i) {
	printf("-------------------------------------------------------------\n");
	printf("%-5s | %-20s | %-30s\n", "ID", "Department", "Area of Expertise");
	printf("-------------------------------------------------------------\n");
	printf("%-5d | %-20s | %-30s\n\n\n", (i+1), doctors[i].position, doctors[i].expertise);
}
void showDeptRoute(int i) {
	i--;
	printf("\nRoute for %s : ", doctors[i].position);
	printf(" %s \n", doctors[i].route);
}
