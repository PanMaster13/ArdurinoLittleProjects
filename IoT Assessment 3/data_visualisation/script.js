var app = angular.module("hindsightApp", []);

app.controller("hindsightCTRL", function($scope, $http){
    
    $http.get("dataset.json")
    .then(
        function (response){
            $scope.sensorData = response.data;
            $scope.temperature = $scope.sensorData.temperature;
            $scope.light = $scope.sensorData.light;
            
            // If temperature more than 30, hot
            // If temperature less than 20, cold
            // If temperature between 20 to 30, normal
            if ($scope.temperature > 30){
                $scope.tempFeedback = "Looks like its pretty hot out there, better stay indoors and have something cold to drink.";
            } else if ($scope.temperature < 20){
                $scope.tempFeedback = "Wow, its pretty chilly out there, best to wear something warm before going outside.";
            } else {
                $scope.tempFeedback = "Guess the temperature is normal, why not go outside and explore!";
            }
            
            // If light more than 300, day
            // If light less than 300, night
            if ($scope.light > 300){
                $scope.lightFeedback = "Guess the sun is up. Stay safe out there."
            } else if ($scope.light <= 299){
                $scope.lightFeedback = "Looks like the sun is down. Be careful friend."
            }
        },
        function (response){
            
        }
    );
    
});