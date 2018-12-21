pipeline {
  stages{
    stage("Checkout"){
      steps {
        deleteDir()

        checkout scm
        sh 'git submodule update --init --recursive'
      }
    }

    stage("Workspace Cleanup"){
      steps {
        sh 'make clean-all'
      }
    }

    stage("Build Info"){
      steps {
        sh 'make info'
      }
    }

    stage("Build Builder Image"){
      steps {
        sh 'make build-image'
      }
    }

    stage("Compile"){
      steps {
        sh 'make build'
      }
    }

    stage("Run Tests"){
      steps {
        sh 'make test'
        junit '**/*test*.xml'
      }
    }

  }
}


