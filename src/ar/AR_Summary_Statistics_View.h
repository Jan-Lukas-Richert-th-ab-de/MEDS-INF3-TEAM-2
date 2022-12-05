// AR_Summary_Statistics_View_h
//   Created by Anas Karah on 30/11/22

#ifndef AR_SUMMARY_STATISTICS_VIEW_H
#define AR_SUMMARY_STATISTICS_VIEW_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class AR_Summary_Statistics_View_Doctor

{
public:
   AR_Summary_Statistics_View_Doctor();
   ~AR_Summary_Statistics_View_Doctor();

   void setDoctorName(string);
   void setDoctorID(string);

   void setDoctorWorkingDays(string);
   void setDoctorWorkingYears(string);

   void setDoctorNumberOfPatients(string);
   void setDoctorNumberOfAppointments(string);

   void setDoctorNumberOfPatientsPerDay(string);
   void setDoctorNumberOfAppointmentsPerDay(string);

   void setDoctorNumberOfPatientsPerMonth(string);
   void setDoctorNumberOfAppointmentsPerMonth(string);

   void setDoctorNumberOfPatientsPerYear(string);
   void setDoctorNumberOfAppointmentsPerYear(string);

   void setDoctorNumberOfPatientsPerWeek(string);
   void setDoctorNumberOfAppointmentsPerWeek(string);

   string getDoctorName();
   string getDoctorID();

   string getDoctorWorkingHours();
   string getDoctorWorkingDays();

   string getDoctorWorkingYears();

   string getDoctorNumberOfPatients();
   string getDoctorNumberOfAppointments();

   string getDoctorNumberOfAppointmentsPerDay();
   string getDoctorNumberOfPatientsPerMonth();
   ;

   string getDoctorNumberOfAppointmentsPerMonth();
   string getDoctorNumberOfPatientsPerYear();

   string getDoctorNumberOfAppointmentsPerYear();
   string getDoctorNumberOfPatientsPerWeek();

   string getDoctorNumberOfPrescriptionsPerWeek();
   string getDoctorNumberOfAppointmentsPerWeek();

private:
   string DoctorName;
   string DoctorID;

   string DoctorWorkingHours;
   string DoctorWorkingDays;
   string DoctorWorkingYears;

   string DoctorNumberOfPatients;
   string DoctorNumberOfAppointments;

   string DoctorNumberOfPatientsPerDay;
   string DoctorNumberOfAppointmentsPerDay;

   string DoctorNumberOfPatientsPerWeek;
   string DoctorNumberOfAppointmentsPerWeek;

   string DoctorNumberOfPatientsPerMonth;
   string DoctorNumberOfAppointmentsPerMonth;

   string DoctorNumberOfPatientsPerYear;
   string DoctorNumberOfAppointmentsPerYear;
};

class AR_Summary_Statistics_View_Room
{
public:
   AR_Summary_Statistics_View_Room();
   ~AR_Summary_Statistics_View_Room();

   void setRoomName(string);
   void setRoomID(string);
   void setRoomType(string);

   void setRoom(string);

   void setRoomNumberOfAppointments(string);

   void setRoomPerDay(string);

   void setRoomNumberOfAppointmentsPerDay(string);

   void setRoomPerMonth(string);

   void setRoomNumberOfAppointmentsPerMonth(string);

   void setRoomPerYear(string);

   void setRoomNumberOfAppointmentsPerYear(string);
   ;
   void setRoomPerWeek(string);

   void setRoomNumberOfAppointmentsPerWeek(string);

   string getRoomName();
   string getRoomID();
   string getRoomType();

   string getRoom();

   string getRoomNumberOfAppointments();

   string getRoomNumberOfAppointmentsPerDay();

   string getRoomNumberOfAppointmentsPerMonth();

   string getRoomNumberOfAppointmentsPerYear();

   string getRoomNumberOfAppointmentsPerWeek();

private:
   string RoomName;
   string RoomID;
   string RoomType;

   string RoomNumberOfAppointmentsPerDay;

   string RoomNumberOfAppointmentsPerWeek;

   string RoomNumberOfAppointmentsPerMonth;

   string RoomNumberOfAppointmentsPerYear;
};

#endif /* AR_Summary_Statistics_View_h */
       /*std::string FD_DA_Patient_Repository_FileBasedImpl::create_storage_record_from_patient(unsigned int id, const ER_Patient &patient)
       {
         std::string result{};
         result.append(std::to_string(id));
         result.append(",");
         result.append(patient.get_first_name());
         result.append(",");
         result.append(patient.get_last_name());
         return result;
       };*/