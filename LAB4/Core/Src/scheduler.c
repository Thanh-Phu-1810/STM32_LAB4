///*
// * scheduler.c
// *
// *  Created on: Nov 10, 2024
// *      Author: Thanh Phu
// */
//
//#include "scheduler.h"
//
//sTasks SCH_tasks_G[SCH_MAX_TASKS];
//uint8_t current_index_task = 0;
//void SCH_Init(void)
//{
//	unsigned int i;
//	for(i = 0; i < SCH_MAX_TASKS; i++)
//	{
//		SCH_Delete(i);
//	}
//	current_index_task = 0;
//
//}
//void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
//{
//	if(current_index_task < SCH_MAX_TASKS)
//	{
//		SCH_tasks_G[current_index_task].pTask = pFunction;
//		SCH_tasks_G[current_index_task].Delay = DELAY;
//		SCH_tasks_G[current_index_task].Period = PERIOD / 10;
//		SCH_tasks_G[current_index_task].RunMe = 0;
//		SCH_tasks_G[current_index_task].TaskID = current_index_task;
//		current_index_task++;
//	}
//}
//void SCH_Update(void) //0(1)
//{
//	for(int i = 0; i < current_index_task; i++)
//	{
//		if(SCH_tasks_G[i].pTask)
//		{
//			if(SCH_tasks_G[i].Delay > 0)
//			{
//				SCH_tasks_G[i].Delay--;
//			}
//			if(SCH_tasks_G[i].Delay == 0)
//			{
//				SCH_tasks_G[i].RunMe++;
//				if(SCH_tasks_G[i].Period > 0) //chu y cho nay
//				{
//					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
//				}
//			}
//		}
//	}
//}
//void SCH_Dispatch_Tasks(void)
//{
//	for(int i = 0; i < current_index_task; i++)
//	{
//		if(SCH_tasks_G[i].RunMe > 0)
//		{
//			(*SCH_tasks_G[i].pTask)();
//			SCH_tasks_G[i].RunMe--;
//			if(SCH_tasks_G[i].Period == 0)
//			{
//				SCH_Delete(SCH_tasks_G[i].TaskID);
//			}
//
//		}
//	}
//}
//void SCH_Delete(uint32_t ID)
//{
//    if (ID < current_index_task)
//    {
//        for (int i = ID; i < current_index_task - 1; i++)
//        {
//            SCH_tasks_G[i] = SCH_tasks_G[i + 1];
//        }
//        current_index_task--;
//
//        SCH_tasks_G[current_index_task].pTask = 0x0000;
//        SCH_tasks_G[current_index_task].Delay = 0;
//        SCH_tasks_G[current_index_task].Period = 0;
//        SCH_tasks_G[current_index_task].RunMe = 0;
//        SCH_tasks_G[current_index_task].TaskID = 0;
//    }
//}





//---------------Dung linklist va ham update la O(1)
#include "scheduler.h"
#include <stdlib.h>

TaskNode_t *head = NULL;  // Con trỏ đến node đầu tiên của linked list
uint32_t globalTick = 0;  // Biến global Tick để theo dõi thời gian

// Hàm khởi tạo linked list rỗng
void SCH_Init(void) {
    head = NULL;
    globalTick = 0;  // Khởi tạo tick toàn cục
}

// Hàm thêm một task mới vào linked list
void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    TaskNode_t *newTask = (TaskNode_t *)malloc(sizeof(TaskNode_t));
    if (newTask == NULL) return; // Kiểm tra nếu không đủ bộ nhớ

    newTask->pTask = pFunction;
    newTask->Delay = DELAY;  // Độ trễ ban đầu
    newTask->Period = PERIOD / 10;  // Chu kỳ thực thi
    newTask->RunMe = 0;  // Biến đếm số lần thực thi
    newTask->next = head;  // Chèn vào đầu danh sách
    head = newTask;
}

// Hàm cập nhật các task (chỉ tăng giá trị thời gian)
void SCH_Update(void) {
    globalTick++;  // Tăng giá trị global tick mỗi khi cập nhật
}

// Hàm thực thi các task đã sẵn sàng
void SCH_Dispatch_Tasks(void) {
    TaskNode_t *current = head;
    TaskNode_t *previous = NULL;

    while (current != NULL) {
        if (current->Delay <= globalTick) {  // Kiểm tra nếu task đã đến thời gian thực thi
            current->RunMe++;  // Đánh dấu task cần thực thi

            // Nếu task có chu kỳ, cập nhật lại Delay
            if (current->Period > 0) {
                current->Delay = globalTick + current->Period;  // Cập nhật thời gian thực thi tiếp theo
            }
        }

        // Nếu task cần được thực thi
        if (current->RunMe > 0) {
            (*current->pTask)();  // Thực thi nhiệm vụ
            current->RunMe--;  // Giảm số lần thực thi của task

            // Xóa task nếu nó chỉ cần chạy một lần
            if (current->Period == 0) {
            	TaskNode_t *temp = current; //lưu địa chỉ node cần xóa

				if (previous == NULL) //nếu node cần xóa là nút đầu tiên
				{
					head = current->next;
				}
				else
				{
					previous->next = current->next;
				}
				current = current->next;
				free(temp); //giải phóng bộ nhớ của node đã bị xóa tránh trường hợp bị rò rỉ bộ nhớ
				continue;
            }
        }

        previous = current;
        current = current->next;
    }
}

// Hàm xóa một task từ linked list
void SCH_Delete(TaskNode_t *task) {
    if (head == NULL || task == NULL) return;

    // Nếu node cần xóa là node đầu tiên
    if (head == task) {
        head = head->next;
        free(task);
        return;
    }

    TaskNode_t *current = head;
    while (current->next != NULL && current->next != task) {
        current = current->next;
    }

    // Nếu tìm thấy node cần xóa
    if (current->next == task) {
        current->next = task->next;
        free(task);
    }
}





//-----------Dung linklist nhung ham update là O(n)------------------
//#include "scheduler.h"
//#include <stdlib.h>
//
//// Con trỏ đến node đầu tiên của linked list
//TaskNode_t *head = NULL;
//
//// Hàm khởi tạo linked list rỗng
//void SCH_Init(void) {
//    head = NULL;
//}
//
//// Hàm thêm một task mới vào linked list
//void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
//    TaskNode_t *newTask = (TaskNode_t *)malloc(sizeof(TaskNode_t));
//    if (newTask == NULL) return; // Kiểm tra nếu không đủ bộ nhớ
//
//    newTask->pTask = pFunction;
//    newTask->Delay = DELAY;
//    newTask->Period = PERIOD / 10;
//    newTask->RunMe = 0;
//    newTask->next = head;
//    head = newTask;
//}
//
//// Hàm cập nhật các task, độ phức tạp O(1)
//void SCH_Update(void) {
//    TaskNode_t *current = head;
//    while (current != NULL) {
//        if (current->Delay > 0) {
//            current->Delay--;
//        }
//        if (current->Delay == 0) {
//            current->RunMe++;
//            if (current->Period > 0) {
//                current->Delay = current->Period;
//            }
//        }
//        current = current->next;
//    }
//}
//
//// Hàm thực thi các task đã sẵn sàng
//void SCH_Dispatch_Tasks(void) {
//    TaskNode_t *current = head;
//    TaskNode_t *previous = NULL;
//
//    while (current != NULL) {
//        if (current->RunMe > 0) {
//            (*current->pTask)(); // Thực thi nhiệm vụ
//            current->RunMe--;
//
//            // Xóa task nếu nó chỉ cần thực thi một lần
//            if (current->Period == 0) {
//                TaskNode_t *temp = current; //lưu địa chỉ node cần xóa
//
//                if (previous == NULL) //nếu node cần xóa là nút đầu tiên
//                {
//                    head = current->next;
//                }
//                else
//                {
//                    previous->next = current->next;
//                }
//                current = current->next;
//                free(temp); //giải phóng bộ nhớ của node đã bị xóa tránh trường hợp bị rò rỉ bộ nhớ
//                continue;
//            }
//        }
//        previous = current; //chỉ gán khi node previous chưa bị xóa
//        current = current->next;
//    }
//}
//
//// Hàm xóa một task từ linked list
//void SCH_Delete(TaskNode_t *task) {
//    if (head == NULL || task == NULL) return;
//
//    // Nếu node cần xóa là node đầu tiên
//    if (head == task) {
//        head = head->next;
//        free(task);
//        return;
//    }
//
//    TaskNode_t *current = head;
//    while (current->next != NULL && current->next != task) {
//        current = current->next;
//    }
//
//    // Nếu tìm thấy node cần xóa
//    if (current->next == task) {
//        current->next = task->next;
//        free(task);
//    }
//}
