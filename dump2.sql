-- MySQL dump 10.13  Distrib 8.0.32, for Linux (x86_64)
--
-- Host: localhost    Database: tgbot
-- ------------------------------------------------------
-- Server version	8.0.32-0ubuntu0.22.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users` (
  `tgid` varchar(30) DEFAULT NULL,
  `username` varchar(100) DEFAULT NULL,
  `time_of_start` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `accmode` int DEFAULT NULL,
  `num_of_req` int DEFAULT '10',
  `changet_neiro` int DEFAULT '1',
  `limit_req` int DEFAULT NULL,
  `context` longtext,
  `role` varchar(100) DEFAULT NULL,
  `rolestat` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES ('539565189','hujara','2023-03-09 06:09:18',3,8,1,70,'Ответь на запрос учитываю предыдущие сообщения(не пиши перед своим сообщением слово Ты:):\n','',0),('553833137','jan_fedorov','2023-03-09 12:23:36',1,10,2,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('1725930153','','2023-03-10 17:50:12',1,10,1,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('1147842892','Fazermatik','2023-03-11 11:55:32',1,10,1,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('538432713','yansama71','2023-03-11 12:00:51',1,10,1,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('1564209879','JustRiyse','2023-03-15 20:17:15',1,10,2,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('484200076','apotaskyn','2023-03-21 20:17:06',1,10,1,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('312394772','EW8TX','2023-03-22 09:25:04',1,10,2,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('783260871','v040404','2023-04-22 13:20:08',3,8,1,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('2016968647','saucedrososa','2023-04-30 19:00:30',1,9,2,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('1914717687','whigyy','2023-04-30 19:01:00',1,7,2,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('466419872','ahu1sh','2023-04-30 19:01:30',1,9,1,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('1237649222','dispater47','2023-04-30 19:02:28',1,9,2,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0),('6030032705','kiresxx','2023-05-04 08:43:09',1,9,2,10,'Ответь на запрос учитываю предыдущие сообщения(перед сообщением НЕ ПИСАТЬ Ты:):\n','',0);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-05-04 17:28:13
